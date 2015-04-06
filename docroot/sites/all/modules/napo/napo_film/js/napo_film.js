(function($){
    Drupal.behaviors.napo_film_load_episode = {
        attach: function (context, settings) {
            $('a.napo_film_episode_link,  .napo_film_episode_link a').once('napo_film_episode_link', function(){
                var nid = $(this).data('nid');
                if (typeof nid != 'undefined') {
                    var ajax_settings = {};
                    ajax_settings.url = '/napo_film/ajax/episode/' + nid;
                    ajax_settings.event = 'click';
                    var base = 'a.napo_film_episode_link,  .napo_film_episode_link a';
                    Drupal.ajax['napo_episode_load'] = new Drupal.ajax(base, this, ajax_settings);
                }
            });
            $('.modal').on('shown.bs.modal', function() {
                $(window).trigger('resize');
                $('.view-id-episode_list.view-display-id-block_1').show();
            });
            $('.modal').on('show.bs.modal', function() {
                $('.view-id-episode_list.view-display-id-block_1').hide();
            });

        }
    };
})(jQuery);