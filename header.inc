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
  <div class="container">

    <div class="page-header">
      <h1>LazyChores</h1>
    </div>

    <ul class="nav nav-tabs">
      <li role="presentation" class="active"><a href="/">Home</a></li>
      <?php print '<li role="presentation"><a href="/user.php?uid=' . $user->uid . '">Log</a></li>'; ?>
    </ul>