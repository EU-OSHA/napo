(function($){
    Drupal.behaviors.napo_film_load_episode = {
        attach: function (context, settings) {
            $('a.napo_film_episode_link,  .napo_film_episode_link a').once('napo_film_episode_link', function(){
                var nid = $(this).data('nid');
                if (typeof nid != 'undefined') {
                    var ajax_settings = {};
                    ajax_settings.url = Drupal.settings.basePath + Drupal.settings.pathPrefix + 'napo_film/ajax/episode/' + nid;
                    ajax_settings.event = 'click';
                    var base = 'a.napo_film_episode_link,  .napo_film_episode_link a';
                    Drupal.ajax['napo_episode_load'] = new Drupal.ajax(base, this, ajax_settings);
                }
            });
            $('.modal').on('shown.bs.modal', function() {
                $(window).trigger('resize');
                $('.view-id-episode_list.view-display-id-block_1').show();

                // Take the value of the title field and set the image title attribute
                var img_title;
                $('ul.jcarousel-view--episode-list--block-1').find('li').each(function(){
                    $(this).mouseover(function(){
                        img_title = '';
                        $(this).find('div.views-field-title-field div.field-content a.napo_film_episode_link').each(function(){
                            img_title = $(this).html().replace('</span>', ': ');
                            img_title = img_title.replace( /<.*?>/g, '' );
                        });
                        if(img_title){
                            $(this).find('div.views-field-nothing span.field-content a.napo_film_episode_link img').each(function(){
                                $(this).attr('title', img_title);
                            });
                            $(this).find('div.views-field-title-field').remove();
                        }
                    })
                })
            });
            $('.modal').on('show.bs.modal', function() {
                $('.view-id-episode_list.view-display-id-block_1').hide();
            });

        }
    };
})(jQuery);