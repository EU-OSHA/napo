<div class="napo-share-widget">
  <span class="napo-share-widget-title">Share</span>
  <ul>
    <li id="fb-share-button-<?php print $node->nid; ?>"  class="napo-share-widget-button" data-href="">Facebook</li>
    <li id="twitter-share-button-<?php print $node->nid; ?>" class="napo-share-widget-button">Twitter</li>
    <li id="gplus-share-button-<?php print $node->nid; ?>" class="napo-share-widget-button">
      <a href="#" onclick="popUp=window.open('https://plus.google.com/share?url=<?php print $url; ?>', 'popupwindow', 'scrollbars=yes,width=800,height=400');popUp.focus();return false">Gogole+</a>
    </li>
  </ul>
</div>

<script>
  (function($) {
    $('#fb-share-button-<?php print $node->nid; ?>').click(function(e) {
        e.preventDefault();
        FB.ui({
          method: 'share',
          href: '<?php print $url ?>'
        }, function (response) {
        });
      }
    );
  })(jQuery);
</script>