jQuery(document).ready(function () {
    jQuery("div.view.view-frontpage-custom-video.view-id-frontpage_custom_video.view-display-id-block").click( function (event) {
        if (jQuery("div.video-js.vjs-default-skin").hasClass("vjs-playing")){
            jQuery("div.views-field.views-field-nothing.frontpage-video-title").show();
        } else {
            jQuery("div.views-field.views-field-nothing.frontpage-video-title").hide();
        }
    });
});

jQuery(document).ready(function () {

    if( jQuery('.btn-back').length > 0 ){
        jQuery('.page--banner--block h1').css('margin-top','5rem');
    }

});

/** CAROUSEL **/
jQuery(document).ready(function () {
    var itemsMainDiv = ('.multicarousel--block');
    var itemsDiv = ('.multicarousel--block--inner');
    var itemWidth = "";

    jQuery('.leftLst, .rightLst').click(function () {
        var condition = jQuery(this).hasClass("leftLst");
        if (condition)
            click(0, this);
        else
            click(1, this)
    });

    ResCarouselSize();

    jQuery(window).resize(function () {
        ResCarouselSize();
    });

    //this function define the size of the items
    function ResCarouselSize() {
        var incno = 0;
        var dataItems = ("data-items");
        var itemClass = ('.item');
        var id = 0;
        var btnParentSb = '';
        var itemsSplit = '';
        var sampwidth = jQuery(itemsMainDiv).width();
        var bodyWidth = jQuery('body').width();
        jQuery(itemsDiv).each(function () {
            id = id + 1;
            var itemNumbers = jQuery(this).find(itemClass).length;
            btnParentSb = jQuery(this).parent().attr(dataItems);
            itemsSplit = btnParentSb.split(',');
            jQuery(this).parent().attr("id", "multicarouselBlock" + id);


            if (bodyWidth >= 1200) {
                incno = itemsSplit[3];
                itemWidth = sampwidth / incno;
            }
            else if (bodyWidth >= 992) {
                incno = itemsSplit[2];
                itemWidth = sampwidth / incno;
            }
            else if (bodyWidth >= 768) {
                incno = itemsSplit[1];
                itemWidth = sampwidth / incno;
            }
            else {
                incno = itemsSplit[0];
                itemWidth = sampwidth / incno;
            }
            jQuery(this).css({ 'transform': 'translateX(0px)', 'width': itemWidth * itemNumbers });
            jQuery(this).find(itemClass).each(function () {
                jQuery(this).outerWidth(itemWidth);
            });

            jQuery(".leftLst").addClass("over");
            jQuery(".rightLst").removeClass("over");

        });
    }


    //this function used to move the items
    function ResCarousel(e, el, s) {

        var leftBtn = ('.leftLst');
        var rightBtn = ('.rightLst');
        var translateXval = '';
        var divStyle = jQuery(el + ' ' + itemsDiv).css('transform');
        var values = divStyle.match(/-?[\d\.]+/g);
        var xds = Math.abs(values[4]);
        if (e == 0) {
            translateXval = parseInt(xds) - parseInt(itemWidth * s);
            jQuery(el + ' ' + rightBtn).removeClass("over");

            if (translateXval <= itemWidth / 2) {
                translateXval = 0;
                jQuery(el + ' ' + leftBtn).addClass("over");
            }
        }
        else if (e == 1) {
            var itemsCondition = jQuery(el).find(itemsDiv).width() - jQuery(el).width();
            translateXval = parseInt(xds) + parseInt(itemWidth * s);
            jQuery(el + ' ' + leftBtn).removeClass("over");

            if (translateXval >= itemsCondition - itemWidth / 2) {
                translateXval = itemsCondition;
                jQuery(el + ' ' + rightBtn).addClass("over");
            }
        }
        jQuery(el + ' ' + itemsDiv).css('transform', 'translateX(' + -translateXval + 'px)');
    }

    //It is used to get some elements from btn
    function click(ell, ee) {
        var Parent = "#" + jQuery(ee).parent().attr("id");
        var slide = jQuery(Parent).attr("data-slide");
        ResCarousel(ell, Parent, slide);
    }

});


/** ACORDION **/
jQuery(document).ready(function () {

    function acordionOpen(elem){
       var contentDiv = jQuery(elem).next();
       var parentDiv = jQuery(elem).parent();
       
       if ( parentDiv.hasClass("active")) {
           jQuery(contentDiv).slideUp(600).fadeOut(600);
           jQuery(parentDiv).removeClass('active');
           jQuery(elem).removeClass('active');
       } else {
           jQuery('.acordion--block--item').removeClass('active');
           jQuery('.acordion-content-title').removeClass('active');
           jQuery('.acordion-content-text').slideUp(600);
           jQuery(contentDiv).slideDown(600).fadeIn(600);
           jQuery(parentDiv).addClass('active');
           jQuery(elem).addClass('active');
       }
    }

    jQuery('.acordion--block h3').click(function () {
        acordionOpen( this );
    });
});




/** MENU RESPONSIVE **/
jQuery(document).ready(function () {

   
    jQuery('header .block-lang-dropdown').prepend('<div class="btn-search-mobile"></div>');
     
    jQuery(window).on("resize",function(e){
        //NRV-84 MOBILE RESOLUTION: Menu items are no reachable when scrolling down
        //jQuery('#block-search-form').removeClass('in');
        //jQuery('header .menu li.dropdown').removeClass('in');
        //jQuery('header .menu li.dropdown').removeClass('open');
        mobileDevice(screen.width);    
         //mobileDevice( jQuery(window).width() );
    });

    mobileDevice(screen.width); 

    function mobileDevice(screen){

        if( screen < 767 ){
            
            if( jQuery(".search--lang--block").parent().attr('class') != 'navbar--toggle--button'){
                jQuery(".search--lang--block").appendTo(".navbar--toggle--button");

                jQuery('.btn-search-mobile').click(function () {
                    jQuery('#block-search-form').toggleClass('in');
                });

                jQuery('form.content-search .btn-primary[type=submit]').click(function () {
                    console.log(jQuery('#edit-search-block-form--2').val().length);
                    if( jQuery('#edit-search-block-form--2').val().length > 0) {
                       // jQuery('#search-block-form').submit();
                        jQuery('#block-search-form').removeClass('in');
                        jQuery('#edit-search-block-form--2').val('');
                    } else {
                        jQuery('#block-search-form').removeClass('in');
                        return false;
                    }
                });
            }


            jQuery('button.navbar-toggle').click(function () {
                jQuery('#block-search-form').removeClass('in');
                if( jQuery('.menu--search--block > .navbar-collapse').hasClass('in') ){
                    jQuery('.menu li.dropdown').removeClass('in');
                }
            });

            if( jQuery('header .menu > li.first a label').length == 0 ){
                jQuery('header .menu > li.first a').append('<label>Home</label>');
            }
            

            jQuery('header .menu li.dropdown > span').once().click(function () {
                element = jQuery(this).parent();
                jQuery('header .menu li.dropdown').removeClass('open');

                if( element.hasClass('in') ){
                    jQuery(element).removeClass('in');
                    jQuery('.caret', this).removeClass('caret-up');
                } else {
                    //jQuery('header .menu li.dropdown').removeClass('in');
                    jQuery( element ).addClass('in');
                    jQuery('.caret', this).addClass('caret-up');
                }            
            });
        
        } else {
            jQuery('#block-search-form').removeClass('in');
            jQuery('.menu li.dropdown').removeClass('in');
            jQuery(".search--lang--block").appendTo(".nav-main-menu");
            if( jQuery('header .menu li.first a label').length > 0 ){
                jQuery('header .menu li.first a label').remove();
            }
        }

    }

});


jQuery(document).ready(function () {
    jQuery('#edit-search').attr('placeholder','Search...');
});


/** node type article **/
jQuery(document).ready(function () {
    var imageWrapper = jQuery('.node-type-article .content .field-name-field-image');
    if(imageWrapper.length == 0){
        jQuery('.node-type-article .content .field-type-text-with-summary').addClass('without-img');
    }

});

/** all block is link for napo's film slider in the home **/
jQuery(document).ready(function () {    
    jQuery('.slider--video--block .slider--video--items .slider-item .lead').click(function () {
        var sliderItemLink = jQuery('a',this).attr('href');
        window.location.href = sliderItemLink;
    });
});


/** DOWNLOAD LESSON BLOCK **/
jQuery(document).ready(function () {
    var downloadList = jQuery('.node-type-lesson .download--section--block ul')
    var numListItems = jQuery('.node-type-lesson .download--section--block ul li').length;
    if( numListItems == 4 ){
        downloadList.addClass('odd');
    }
    if( numListItems == 5 ){
        downloadList.addClass('even');
    }
});


/** DOWNLOAD activities and glossary **/
jQuery(document).ready(function () {
    var labelActivities = jQuery('.node-type-article .field-name-field-activity-list-file .field-label').text();
    var labelActivitiesPrint = labelActivities.substr(0, labelActivities.length-2);

    var labelGlossary = jQuery('.node-type-article .field-name-field-menu .field-label').text();
    var labelGlossaryPrint = labelGlossary.substr(0, labelGlossary.length-2);

    jQuery('.node-type-article .field-name-field-activity-list-file .field-items a').text(labelActivitiesPrint);
    jQuery('.node-type-article .field-name-field-menu .field-items a').text(labelGlossaryPrint);


});


/** video home message **/
jQuery(document).ready(function () {
    var homeVideoText = jQuery('.homepage-video-body').text().length;

    if( homeVideoText > 350 || homeVideoText <= 500 ){
        jQuery('.slider .frontpage-video-title').css('max-width','38rem');
    } 
    if( homeVideoText > 500 ){
        jQuery('.slider .frontpage-video-title').css({'max-width':'42rem',top:'10%',left:'8rem'});
    }

});


/** clean copy paste styles **/
jQuery(document).ready(function () {
    var wrapperDiv = jQuery('.region-content');
/*
    if( jQuery('.region-content p span').attr('style').indexOf('font-size:') != -1 ){
        jQuery('.region-content p span').removeAttr('style');
    }
*/
nElement = jQuery('.region-content p').length ;

for(i=0; i < nElement; i++ ){
    jQuery('.region-content p').removeAttr('style');
    jQuery('.region-content p span').removeAttr('style');
}


/*
    if( jQuery('.region-content p').attr('style').indexOf('font-size:') != -1 ){
        jQuery('.region-content p').removeAttr('style');
    }
*/
});