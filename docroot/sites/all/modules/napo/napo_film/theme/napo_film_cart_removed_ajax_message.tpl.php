<?php
$label = format_plural(count($data), '1 item removed from the Download centre', '@count items removed from the Download centre', array('@count' => count($data)));
?>
<div class="napo-film-added-to-cart-message">
  <div class="napo-film-added-label">
    <?php print $label; ?>
  </div>
  <?php foreach ($data as $node_rendered) { ?>
  <?php print $node_rendered; ?>
  <?php } ?>
  <div class="napo-film-access-download-centre">
    <a href="<?php print url('download-center'); ?>" class="btn btn-primary"><?php print t('Access to Download centre'); ?></a>
  </div>
</div>