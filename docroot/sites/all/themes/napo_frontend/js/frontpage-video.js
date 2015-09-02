jQuery(document).ready(function () {
    jQuery("div.view.view-frontpage-custom-video.view-id-frontpage_custom_video.view-display-id-block").click( function (event) {
        if (jQuery("div.video-js.vjs-default-skin").hasClass("vjs-playing")){
            jQuery("div.views-field.views-field-nothing.frontpage-video-title").show();
        } else {
            jQuery("div.views-field.views-field-nothing.frontpage-video-title").hide();
        }
    });
});
