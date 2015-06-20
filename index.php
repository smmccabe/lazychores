<?php

include 'database.inc';
include 'header.inc';

?>

    <div id="user-wrapper" class="panel panel-default">
      <div class="panel-heading">Profile</div>
      <div class="panel-body">
        <?php

        if(!$user->uid) {
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
        print '<tr><th>Name</th><th>Frequency</th><th>Due</th><th>Size</th><th>Last Done By</th></tr>';

        $result = $db->query("SELECT id FROM chore ORDER BY name DESC");
        while($row = $result->fetch_assoc()) {
          $chore->load($row['id']);
          print '<tr>' . $chore->display() . '</tr>';
        }

        print '</table>';

        print '</div>';

include 'footer.inc';

?>