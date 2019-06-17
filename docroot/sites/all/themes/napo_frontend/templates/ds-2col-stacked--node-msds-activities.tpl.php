<?php

/**
 * @file
 * Display Suite 2 column stacked template.
 */

?>
<section class="page--banner--block">
  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>
    <div class="<?php print $header_classes; ?>">
      <?php print $header; ?>
    </div>
</section>

<section class="detail--section--block">
    <h2><?php print t('Activities'); ?></h2>
    <div class="detail--text--block">
        <div class="<?php print $left_classes; ?>">
          <?php print $left; ?>
        </div>
        <div class="<?php print $header_classes; ?>">
          <?php print $right; ?>
        </div>
    </div>
</section>
