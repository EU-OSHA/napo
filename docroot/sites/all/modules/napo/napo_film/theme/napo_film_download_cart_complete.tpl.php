<?php ?>
<div class="hidden alert alert-success alert-dismissible" role="alert">
  <button type="button" class="close" data-dismiss="alert"><span aria-hidden="true">&times;</span></button>
  <p>
  <?php /* <a href="<?php print $file_path; ?>"><?php print $message; ?></a> */ ?>
    <script>location.replace('<?php print $file_path;?>');</script>
  </p>
</div>