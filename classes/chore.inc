<?php

class chore {
  private $db;

  public $id;
  public $name;
  public $frequency;
  public $last_done;

  function __construct($db) {
    $this->db = $db;
  }

  function load($id) {
    $result = $this->db->query("SELECT * FROM chore WHERE id=$id");
    if($row = $result->fetch_assoc()) {
      $this->id = $row['id'];
      $this->name = $row['name'];
      $this->frequency = $row['frequency'];
    }

    $result = $this->db->query("SELECT * FROM chore_instance WHERE chore_id=$id ORDER BY date DESC LIMIT 1");
    if($row = $result->fetch_assoc()) {
      $this->last_done = new DateTime($row['date']);
    }
  }

  function create($name, $frequency) {
    $this->db->query("INSERT INTO chore(name, frequency) VALUES('$name', '$frequency')");

    $this->name = $name;
    $this->frequency = $frequency;
    $this->id = $this->db->insert_id;
  }

  function form() {
    $output = '<form class="form-inline" method="post">';
    $output .= '<div class="form-group">';
    $output .= '<label class="sr-only">Name</label><input name="chore-name" id="chore-name" class="form-control" type="text" placeholder="name" />';
    $output .= '<label class="sr-only">Frequency</label>';
    $output .= '<select name="chore-frequency" id="chore-frequency" class="form-control">';
    $output .= '<option value="0">One Time</option>';
    $output .= '<option value="1">Daily</option>';
    $output .= '<option value="2">Every 2 Days</option>';
    $output .= '<option value="7">Weekly</option>';
    $output .= '<option value="14">Bi-Weekly</option>';
    $output .= '<option value="30">Monthly</option>';
    $output .= '<option value="60">Bi-monthly</option>';
    $output .= '<option value="90">Quarterly</option>';
    $output .= '<option value="180">Semi-annually</option>';
    $output .= '<option value="365">Annually</option>';
    $output .= '</select>';
    $output .= '<button type="submit" id="chore-button" class="btn btn-primary glyphicon glyphicon-plus"></button>';
    $output .= '</div>';
    $output .= '</form>';

    return $output;
  }

  function form_submit() {
    if(isset($_POST['chore-name']) && isset($_POST['chore-frequency'])) {
      $this->create($_POST['chore-name'], isset($_POST['chore-frequency']));
    }
  }

  function display() {
    if(isset($this->last_done)) {
      $overdue = ((time() - $this->last_done->getTimestamp()) / 86400) - $this->frequency;
    }
    else{
      $overdue = 'Never Done';
    }

    print '<td>' . $this->name . '</td><td>' . $this->display_frequency() . '</td><td>' . $overdue . '</td><td><button type="submit" id="chore-done" class="btn btn-primary glyphicon glyphicon-check"></button></td>';
  }

  function display_frequency() {
    switch($this->frequency) {
      case 0:
        return 'One Time';
      case 1:
        return 'Daily';
      case 2:
        return 'Every 2 Days';
      case 7:
        return 'Weekly';
      case 14:
        return 'Bi-Weekly';
      case 30:
        return 'Monthly';
      case 60:
        return 'Bi-Monthly';
      case 90:
        return 'Quarterly';
      case 180:
        return 'Semi-Annually';
      case 365:
        return 'Annually';
    }
  }
}