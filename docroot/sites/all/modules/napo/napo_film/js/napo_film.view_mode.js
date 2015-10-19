(function($){
    Drupal.behaviors.napo_film_view_mode = {
        attach: function (context, settings) {
            // Set the view mode
            var selected_view_mode = napo_film_get_view_mode();
            var cookie = napo_film_get_cookie("view_mode");
            if (cookie != selected_view_mode) {
                document.cookie = 'view_mode=' + selected_view_mode +'; path=/';
            }

            // Find all links to napo-films and append the view mode parameter.
            $('a[href*="/napos-films/films"]').not('[data-set-view-mode="page_list"], [data-set-view-mode="page_grid"]').once('napo_film_view_mode', function(){
                var link = URI($(this).attr('href'));
                link.removeSearch('view_mode');
                link.addSearch('view_mode', selected_view_mode);
                $(this).attr('href', link);
            });

            function napo_film_get_view_mode() {
                // If current uri has a view mode, this will be the view mode.
                var uri = URI(window.location);
                if (uri.hasQuery('view_mode', 'page_list')) {
                    return 'page_list'
                }
                else if (uri.hasQuery('view_mode', 'page_grid')) {
                    return 'page_grid'
                }

                // If view mode not in uri, the view mode will be form cookie.
                var cookie = napo_film_get_cookie("view_mode");
                if (cookie == '') {
                    return 'page_grid';
                }
                else {
                    return cookie;
                }
            }

            function napo_film_get_cookie(cname) {
                var name = cname + "=";
                var ca = document.cookie.split(';');
                for(var i=0; i<ca.length; i++) {
                    var c = ca[i];
                    while (c.charAt(0)==' ') c = c.substring(1);
                    if (c.indexOf(name) == 0) return c.substring(name.length,c.length);
                }
                return "";
            }
        }
    };
})(jQuery);