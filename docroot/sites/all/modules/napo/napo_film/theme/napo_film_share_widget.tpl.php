<div class="napo-share-widget">
  <span class="napo-share-widget-title">Share</span>
  <ul>
    <li id="fb-share-button-<?php print $node->nid; ?>"  class="napo-share-widget-button" data-href="">Facebook</li>
    <li id="twitter-share-button-<?php print $node->nid; ?>" class="napo-share-widget-button">
      <a href="<?php print $tweet_url; ?>">
        Twitter
      </a></li>
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

    $('#twitter-share-button-<?php print $node->nid; ?> a').click(function(event) {
      var width  = 575,
        height = 400,
        left   = ($(window).width()  - width)  / 2,
        top    = ($(window).height() - height) / 2,
        url    = this.href,
        opts   = 'status=1' +
          ',width='  + width  +
          ',height=' + height +
          ',top='    + top    +
          ',left='   + left;

      window.open(url, 'twitter', opts);

      return false;
    });
  })(jQuery);
</script>