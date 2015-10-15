<div id="top_menu_lessons_container">
  <ul id="top_menu_lessons" class="nav nav-right-menu nav-stacked">
    <?php foreach($lessons as $key => $lesson): ?>
      <li class="<?php echo $node->nid == $lesson->nid? 'lesson active':'lesson'; ?>">
        <?php echo l(t('Lesson @no', array('@no' => ($key + 1))), 'node/'.$lesson->nid); ?>
      </li>
    <?php endforeach; ?>
  </ul>
</div>
