<?php

// render recommended films from preprocess_node
if (!empty($vars['recommended_films_nodes'])) { ?>
  <div id="recommended_films">
    <div class="recommended_films_head"><?php print t('Other films recommended for you');?></div>
  </div>
  <?php
    foreach ($vars['recommended_films_nodes'] as $recommended) {
      print render($recommended);
    }
}
