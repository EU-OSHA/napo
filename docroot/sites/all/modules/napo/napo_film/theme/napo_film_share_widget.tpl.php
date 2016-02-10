<div class="napo-share-widget">
  <span class="napo-share-widget-title"><?php t('Share'); ?></span>
  <ul>
    <li id="fb-share-button-<?php print $node->nid; ?>"  class="napo-share-widget-button napo-share-widget-facebook">
      <a onclick="window.open(this.href, 'hwc-share', 'left=20,top=20,width=500,height=500,toolbar=1,resizable=0'); return false;"
        href="https://www.facebook.com/sharer/sharer.php?u=<?php print $url ?>">Facebook
      </a>
    </li>
    <li id="twitter-share-button-<?php print $node->nid; ?>" class="napo-share-widget-button napo-share-widget-twitter">
      <a href="<?php print $tweet_url; ?>">
        Twitter
      </a></li>
    <li id="gplus-share-button-<?php print $node->nid; ?>" class="napo-share-widget-button napo-share-widget-gplus">
      <a href="#" onclick="popUp=window.open('https://plus.google.com/share?url=<?php print $url; ?>', 'popupwindow', 'scrollbars=yes,width=800,height=400');popUp.focus();return false">Google+</a>
    </li>
    <li id="linked-in-<?php print $node->nid; ?>" class="napo-share-widget-button napo-share-widget-linkedin">Linked in</li>
  </ul>
</div>

<script>
  (function($) {
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

    $('#linked-in-<?php print $node->nid; ?>').click(function() {
      var url = "https://www.linkedin.com/shareArticle?mini=true&url=<?php print $url ?>";
      var width  = 575,
        height = 400,
        left   = ($(window).width()  - width)  / 2,
        top    = ($(window).height() - height) / 2,
        opts   = 'status=1' +
          ',width='  + width  +
          ',height=' + height +
          ',top='    + top    +
          ',left='   + left;
      window.open(url, 'Linked In', opts);
    });
  })(jQuery);


</script>