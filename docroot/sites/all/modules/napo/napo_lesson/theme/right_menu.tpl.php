<style type="text/css">
  /* Custom Styles */
  ul.nav-right-menu{
    width: 300px;
    margin-top: 20px;
    border-radius: 4px;
    border: 1px solid #ddd;
    box-shadow: 0 1px 4px rgba(0, 0, 0, 0.067);
  }
  ul.nav-right-menu li{
    margin: 0;
    border-top: 1px solid #ddd;
  }
  ul.nav-right-menu li:first-child{
    border-top: none;
  }
  ul.nav-right-menu li a{
    margin: 0;
    padding: 8px 16px;
    border-radius: 0;
  }
  ul.nav-right-menu li.active a, ul.nav-right-menu li.active a:hover{
    color: #fff;
    background: #0088cc;
    border: 1px solid #0088cc;
  }
  ul.nav-right-menu li:first-child a{
    border-radius: 4px 4px 0 0;
  }
  ul.nav-right-menu li:last-child a{
    border-radius: 0 0 4px 4px;
  }
  ul.nav-right-menu.affix{
    top: 30px; /* Set the top position of pinned element */
  }
  .node-lesson .group-right{
    float: right;
  }
</style>
<div class="scrollspy">
  <ul id="menu-about-page-menu" class="nav nav-right-menu nav-stacked">
    <li>Lessons</li>
  </ul>
</div>