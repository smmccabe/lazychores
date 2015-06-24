<?php

include 'database.inc';
include 'header.inc';

        $chore = new chore($db);
        $chore->form_submit();

        print '<div class="panel panel-default">';
        print '<div class="panel-heading">Chores</div>';
        print $chore->form();

        print '<table id="chore-list" class="table tablesorter">';
        print '<thead><tr><th>Name</th><th>Frequency</th><th>Due</th><th>Size</th><th class="hidden-xs">Last Done By</th><th></th></tr></thead>';
        print '<tbody>';

        $result = $db->query("SELECT id FROM chore ORDER BY name DESC");
        while($row = $result->fetch_assoc()) {
          $chore->load($row['id']);

          //@TODO - this doesn't scale great, might have to fix later
          if (!($chore->frequency == 0 && isset($chore->last_done))) {
            print '<tr>' . $chore->display() . '</tr>';
          }
        }

        print '</tbody>';
        print '</table>';

        print '</div>';

include 'footer.inc';

?>