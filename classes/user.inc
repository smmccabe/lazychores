<?php

class user {
  private $db;

  public $uid;
  public $name;
  public $email;

  function __construct($db) {
    $this->db = $db;
  }

  function create_or_load($email, $password, $name = '') {
    if(!$this->load($email, $password)){
      $this->create($email, $password, $name);
    }
  }

  function create($email, $password, $name) {
    $password = password_hash($password, PASSWORD_DEFAULT);

    $this->db->query("INSERT INTO user(name, email, password) VALUES('$name', '$email', '$password')");
    $this->uid = $this->db->insert_id;

    $_SESSION['uid'] = $this->uid;
  }

  function load($email = null, $password = null){
    if(!isset($email)){
      if(isset($_SESSION['uid'])) {
        return $this->load_uid($_SESSION['uid']);
      }
      else{
        return FALSE;
      }
    }
    else{
      return $this->load_email($email, $password);
    }
  }

  function load_uid($uid) {
    $this->uid = $uid;
    $result = $this->db->query("SELECT email, name FROM user WHERE uid='$uid'");
    if($row = $result->fetch_assoc()){
      $this->email = $row['email'];
      $this->name = $row['name'];
      $_SESSION['uid'] = $this->uid;
      return TRUE;
    }

    return FALSE;
  }

  function load_email($email, $password){
    $this->email = $email;
    $result = $this->db->query("SELECT uid, name, password FROM user WHERE email='$email'");
    if($row = $result->fetch_assoc()){
      if(password_verify($password, $row['password'])) {
        $this->uid = $row['uid'];
        $this->name = $row['name'];
        $_SESSION['uid'] = $this->uid;
        return TRUE;
      }
    }

    return FALSE;
  }

  function form() {
    $output = '<form class="form-inline" method="post">';
    $output .= '<div class="form-group">';
    $output .= '<label class="sr-only">Email</label><input name="email" id="user-email" class="form-control" type="email" placeholder="email" />';
    $output .= '<label class="sr-only">Password</label><input name="password" id="user-password" class="form-control" type="password" placeholder="password" />';
    $output .= '<button type="submit" id="user-button" class="btn btn-primary glyphicon glyphicon-log-in"></button>';
    $output .= '</div>';
    $output .= '</form>';

    return $output;
  }
}