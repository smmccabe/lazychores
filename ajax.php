<?php

include "database.inc";

if(isset($_GET['action'])) {
  switch ($_GET['action']) {
    case 'log':
      if(isset($_GET['chore_id']) && isset($_SESSION['uid'])) {
        $chore = new chore($db);
        $chore->load($_GET['chore_id']);
        $chore->log($_SESSION['uid']);

        print "Chore Logged";
      }
  }
}