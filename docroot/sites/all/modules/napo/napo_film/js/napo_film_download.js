(function($){
    Drupal.behaviors.napo_film_download_form = {
        attach: function (context, settings) {
            // Fix for Ipad label not clickable.
            $('label').once('napo_film_download_form', function(){
                $(this).click(function(){});
            });
        }
    };
})(jQuery);