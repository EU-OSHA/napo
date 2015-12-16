<?php

// Reverse array to show the latest 4.
$data = array_reverse($data);
$label = format_plural(count($data), '1 item added to the Download centre', '@count items added to the Download centre', array('@count' => count($data)));
$label_more = '';
// Only show 4 thumbnails. If more than 4, add a label.
$showing_data = array_slice($data, 0, 4);
$more_items_count = count($data) - count($showing_data);
if (count($data) > 4) {
  $label_more = format_plural($more_items_count, 'and 1 item more', 'and @count items more', array('@count' => $more_items_count));
}
?>
<div class="napo-film-added-to-cart-message">
  <div class="napo-film-added-label">
    <?php print $label; ?>
  </div>
  <?php foreach ($showing_data as $node_rendered) { ?>
    <?php print $node_rendered; ?>
  <?php } ?>
  <?php if (!empty($label_more)) { ?>
  <div class="napo-film-added-label-more">
    <?php print $label_more; ?>
  </div>
  <?php  } ?>
  <div class="napo-film-access-download-centre">
    <a href="<?php print url('download-center'); ?>" class="btn btn-primary"><?php print t('Access to Download centre'); ?></a>
  </div>
</div>