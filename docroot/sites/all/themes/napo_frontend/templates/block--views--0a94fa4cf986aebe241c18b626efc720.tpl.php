<?php
/**
 * @file
 * Returns the HTML for a block.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728246
 *
 */

//todo link to napo film
//http://napo.local.ro/en/napos-films/films?view_mode=page_grid
// todo... data-items
?>
<?php
$translated = osha_tmgmt_literal_get_translation('Napo\'s films');
?>
<section class="container slider--video--section">
    <div class="slider--video--block row">
        <div class="slider--video--items">
            <h2 class="block-title"><a href="napos-films/films"><?php print $translated; ?></a></h2>
            <?php print $content; ?>
        </div>
    </div>
</section>