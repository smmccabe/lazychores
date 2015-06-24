$(function() {

  $('.log').click(function () {
    var chore_id = $(this).data('chore_id');
    var parent = this;

    $.get("ajax.php", {action: 'log', chore_id: chore_id}).done(function (data) {
      $(parent).parent().html(data);
    });
  });

  $(".datepicker" ).datepicker();

  $("#chore-list").tablesorter({

    textExtraction: function(node) {
      return node.innerHTML.replace(" days", "");
    }
  });

});