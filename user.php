<?php

include 'database.inc';
include 'header.inc';

?>

  <div class="panel panel-default">
    <div class="panel-body">

<?php

if(isset($user->uid)){
  $total = 0;

  print '<table class="table">';
  print '<tr><th>Chore</th><th>Size</th><th>Date</th></tr>';

  $result = $db->query("SELECT * FROM chore_instance AS ci JOIN chore AS c ON c.id=ci.chore_id WHERE uid=$user->uid ORDER BY ci.date DESC");



  while($row = $result->fetch_assoc()) {
    $total += $row['size'];
    print '<tr><td>' . $row['name'] . '</td><td>' . $row['size'] . '</td><td>' . $row['date'] . '</td></tr>';
  }

  print '<tr><td><strong>Total:</strong></td><td><strong>' . $total . '</strong></td><td></td></tr>';
  print '</table>';
}

print '</div>';
print '</div>';

include 'footer.inc';

?>