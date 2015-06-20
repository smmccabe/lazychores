<?php

include "database.inc";

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
  <script src="script.js"></script>

  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.4/css/bootstrap.min.css">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.4/css/bootstrap-theme.min.css">
  <link rel="stylesheet" type="text/css" href="style.css">

  <title>LazyChores</title>
</head>
<body>
  <div id="site-wrapper" class="container">

    <div class="page-header">
      <h1>LazyChores</h1>
      <small><p>Simple chore tracker</p></small>
    </div>

    <div id="user-wrapper" class="panel panel-default">
      <div class="panel-heading">Profile</div>
      <div class="panel-body">
        <?php

        $user = new user($db);
        if(isset($_POST['email']) && isset($_POST['password'])) {
          $user->create_or_load($_POST['email'], $_POST['password']);
        }

        if($user->load()){
          print $user->email;
        }
        else {
          print $user->form();
        }

        print '</div>';
        print '</div>';

        $chore = new chore($db);
        $chore->form_submit();

        print '<div class="panel panel-default">';
        print '<div class="panel-heading">Chores</div>';
        print $chore->form();

        print '<table class="table">';
        print '<tr><th>Name</th><th>Frequency</th><th>Due</th></tr>';

        $result = $db->query("SELECT id FROM chore ORDER BY name DESC");
        while($row = $result->fetch_assoc()) {
          $chore->load($row['id']);
          print '<tr>' . $chore->display() . '</tr>';
        }

        print '</table>';

        print '</div>';
    ?>

  </div>
</body>
</html>