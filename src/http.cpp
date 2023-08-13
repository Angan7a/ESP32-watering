#include"http.hpp"

string load_page()
{
  //the HTML of the web page
        string page = "";
 page = "<!DOCTYPE HTML>";
 page += "<html>";
 page += "<style>";
 page += "ul {column-count: 3; column-gap: 18rem;}";
 page += "</style>";

page += "<body>";

page += "<p><b>Ustawienia czasu podlewania:</b></p>";
page += "<ul class=\"checkboxes\">";
page += "<form action=\"/act\" method=\"get\">";
page += "<li><label><input type=\"checkbox\" name=\"text24\" value=\"24\" />0:00</label></li>";
page += "<li><label><input type=\"checkbox\" name=\"text1\" value=\"1\" />1:00</label></li>";
page += "<li><label><input type=\"checkbox\" name=\"text2\" value=\"2\" />2:00</label></li>";
page += "<li><label><input type=\"checkbox\" name=\"text3\" value=\"3\" />3:00</label></li>";
page += "<li><label><input type=\"checkbox\" name=\"text4\" value=\"4\" />4:00</label></li>";
page += "<li><label><input type=\"checkbox\" name=\"text5\" value=\"5\" />5:00</label></li>";
page += "<li><label><input type=\"checkbox\" name=\"text6\" value=\"6\" />6:00</label></li>";
page += "<li><label><input type=\"checkbox\" name=\"text7\" value=\"7\" />7:00</label></li>";
page += "<li><label><input type=\"checkbox\" name=\"text8\" value=\"8\" />8:00</label></li>";
page += "<li><label><input type=\"checkbox\" name=\"text9\" value=\"9\" />9:00</label></li>";
page += "<li><label><input type=\"checkbox\" name=\"text10\" value=\"10\" />10:00</label></li>";
page += "<li><label><input type=\"checkbox\" name=\"text11\" value=\"11\" />11:00</label></li>";
page += "<li><label><input type=\"checkbox\" name=\"text12\" value=\"12\" />12:00</label></li>";
page += "<li><label><input type=\"checkbox\" name=\"text13\" value=\"13\" />13:00</label></li>";
page += "<li><label><input type=\"checkbox\" name=\"text14\" value=\"14\" />14:00</label></li>";
page += "<li><label><input type=\"checkbox\" name=\"text15\" value=\"15\" />15:00</label></li>";
page += "<li><label><input type=\"checkbox\" name=\"text16\" value=\"16\" />16:00</label></li>";
page += "<li><label><input type=\"checkbox\" name=\"text17\" value=\"17\" />17:00</label></li>";
page += "<li><label><input type=\"checkbox\" name=\"text18\" value=\"18\" />18:00</label></li>";
page += "<li><label><input type=\"checkbox\" name=\"text19\" value=\"19\" />19:00</label></li>";
page += "<li><label><input type=\"checkbox\" name=\"text20\" value=\"20\" />20:00</label></li>";
page += "<li><label><input type=\"checkbox\" name=\"text21\" value=\"21\" />21:00</label></li>";
page += "<li><label><input type=\"checkbox\" name=\"text22\" value=\"22\" />22:00</label></li>";
page += "<li><label><input type=\"checkbox\" name=\"text23\" value=\"23\" />23:00</label></li>";
page += "</ul>";

return page;
}
