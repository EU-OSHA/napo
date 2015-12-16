<?php
$label = format_plural(count($data), '1 item added to the Download centre', '@count items added to the Download centre', array('@count' => count($data)));
$label_more = '';
$showing_data = array_slice($data, 0, 4);
if (count($data) > 4) {
  $label_more = t('and @count items more', array('@count' => count($data) - count($showing_data)));
}
?>
<div class="napo-film-added-to-cart-message">
  <div class="napo-film-added-label">
    <?php print $label; ?>
  </div>
  <?php foreach ($showing_data as $node_rendered) { ?>
    <?php print $node_rendered; ?>
  <?php } ?>
  <div class="napo-film-added-label-more">
    <?php print $label_more; ?>
  </div>
  <div class="napo-film-access-download-centre">
    <a href="<?php print url('download-center'); ?>" class="btn btn-primary"><?php print t('Access to Download centre'); ?></a>
  </div>
</div>