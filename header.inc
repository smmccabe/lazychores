<?php
  function display_menu($text, $link) {
    $output = '<li role="presentation"';

    if($link == $_SERVER["REQUEST_URI"]) {
      $output .= ' class="active"';
    }
    $output .= '><a href="' . $link . '">' . $text . '</a></li>';

    return $output;
  }
?>

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1">

  <script src="https://ajax.googleapis.com/ajax/libs/jquery/2.1.4/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.4/js/bootstrap.min.js"></script>
  <script src="https://fb.me/react-0.13.3.js"></script>
  <script src="//code.jquery.com/ui/1.11.4/jquery-ui.js"></script>
  <script src="/js/jquery.tablesorter.min.js"></script>
  <script src="/js/script.js"></script>

  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.4/css/bootstrap.min.css">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.4/css/bootstrap-theme.min.css">
  <link rel="stylesheet" href="//code.jquery.com/ui/1.11.4/themes/smoothness/jquery-ui.css">
  <link rel="stylesheet" type="text/css" href="style.css">

  <title>LazyChores</title>
</head>
<body>
<div class="container">

  <div class="page-header">
    <h1><a href="/">LazyChores</a></h1>
  </div>

  <ul class="nav nav-tabs">
    <?php
      print display_menu('Home', '/');
      print display_menu('Log', '/user.php?uid=' . $user->uid);
    ?>
  </ul>

  <?php
  if (!$user->uid) {
  ?>

  <div id="user-wrapper" class="panel panel-default">
    <div class="panel-heading">Login / Create</div>
    <div class="panel-body">
      <?php
      print $user->form();
      ?>
    </div>
  </div>
<?php
}
?>