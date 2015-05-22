<?php

// render recommended films from preprocess_node
if (!empty($vars['recommended_films_nodes'])) { ?>
  <div id="recommended_films">
    <div class="recommended_films_head"><span><?php print t('Other films recommended for you');?><span></div>
    <?php foreach ($vars['recommended_films_nodes'] as $recommended) { ?>
      <div class="napo-film-item-container col-md-4 col-sm-6">
        <?php print render($recommended); ?>
      </div>
    <?php } ?>
  </div>
<?php } ?>
