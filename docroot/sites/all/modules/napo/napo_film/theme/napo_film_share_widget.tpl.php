<div class="napo-share-widget">
  <span class="napo-share-widget-title">Share</span>
  <ul>
    <li id="fb-share-button-<?php print $node->nid; ?>"  class="napo-share-widget-button" data-href="">Facebook</li>
    <li id="twitter-share-button-<?php print $node->nid; ?>" class="napo-share-widget-button">Twitter</li>
    <li id="gplus-share-button-<?php print $node->nid; ?>" class="napo-share-widget-button">Google +</li>
  </ul>
</div>

<script>
  (function($) {
    $('#fb-share-button-<?php print $node->nid; ?>').click(function(e) {
        e.preventDefault();
        console.log('<?php print base_path(); ?>/node/<?php print $node->nid; ?>');
        FB.ui({
          method: 'share',
          href: '<?php print url('/node/' . $node->nid , array('absolute' => TRUE)); ?>'
        }, function (response) {
        });
      }
    );
  })(jQuery);
</script>