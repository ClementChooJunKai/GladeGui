#include <gtk/gtk.h>
#include <string.h>

GtkWidget *window;
GtkWidget *boxPvP;
GtkWidget *player_vs_player;
GtkWidget *player_vs_computer_easy;
GtkWidget *player_vs_computer_medium;
GtkWidget *player_vs_computer_hard;
GtkWidget *quit;
GtkWidget *fixedMainMenu;
GtkWidget *ttcpage;
GtkWidget *ttcgrid;
GtkWidget *ttc1;
GtkWidget *child1;
GtkWidget *ttc2;
GtkWidget *ttc3;
GtkWidget *ttc4;
GtkWidget *ttc5;
GtkWidget *ttc6;
GtkWidget *ttc7;
GtkWidget *ttc8;
GtkWidget *ttc9;
GtkWidget *image;


void hideMenu();
int main (int argc,char *argv[]){
    gtk_init(&argc,&argv);
  

   

    //Creating a window and styling of window
    window =gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"Tic Tac Toe");
    gtk_window_set_default_size(GTK_WINDOW(window),1000,600);
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(window),FALSE);
    //gtk_window_set_decorated(GTK_WINDOW(window),FALSE);
    
    image = gtk_image_new_from_file ("download.jfif");


  
    


    //gtk_widget_show (fixed);
    //creating a fixed container
    fixedMainMenu = gtk_fixed_new ();
    
    gtk_widget_set_name(fixedMainMenu,"fixedMainMenu");
    
    gtk_container_add (GTK_CONTAINER (window), fixedMainMenu);
    
    //creating box container
    boxPvP = gtk_fixed_new();
    ttcpage = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
    gtk_container_add(GTK_CONTAINER(fixedMainMenu),boxPvP);
    gtk_container_add (GTK_CONTAINER (fixedMainMenu), ttcpage);
    gtk_widget_set_name(boxPvP,"boxPvP");
    gtk_widget_set_name(ttcpage,"ttcpage");
   
   
    
    //Main Menu
    //creating elements in main menu 
    player_vs_player = gtk_button_new_with_label("Player Vs Player");
    player_vs_computer_easy = gtk_button_new_with_label("Player Versus Computer(Easy)");
    player_vs_computer_medium= gtk_button_new_with_label("Player Versus Computer(Medium)");
    player_vs_computer_hard= gtk_button_new_with_label("Player Versus Computer(Hard)");
    quit= gtk_button_new_with_label("Back");
    gtk_container_add(GTK_CONTAINER(boxPvP),player_vs_computer_easy);
    gtk_widget_set_name(player_vs_computer_easy,"player_vs_computer_easy");
    gtk_container_add(GTK_CONTAINER(boxPvP),player_vs_player);
    gtk_widget_set_name(player_vs_player,"player_vs_player");
    gtk_container_add(GTK_CONTAINER(boxPvP),quit);
    gtk_widget_set_name(quit,"quit");
    gtk_container_add(GTK_CONTAINER(boxPvP),player_vs_computer_hard);
    gtk_widget_set_name(player_vs_computer_hard,"player_vs_computer_hard");
    gtk_container_add(GTK_CONTAINER(boxPvP),player_vs_computer_medium);
    gtk_widget_set_name(player_vs_computer_medium,"player_vs_computer_medium");

    

    //Tic tac toe page 
    //creating elements in page ttc
    ttcgrid = gtk_grid_new();
    gtk_widget_set_name(ttcgrid,"ttcgrid");
    gtk_container_add(GTK_CONTAINER(ttcpage),ttcgrid);
    

    ttc1 = gtk_button_new_with_label("");
    ttc2 = gtk_button_new_with_label("TTC2");
    ttc3 = gtk_button_new_with_label("TTC3");
    ttc4 = gtk_button_new_with_label("TTC4");
    ttc5 = gtk_button_new_with_label("TTC5");
    ttc6 = gtk_button_new_with_label("TTC6");
    ttc7 = gtk_button_new_with_label("TTC7");
    ttc8 = gtk_button_new_with_label("TTC8");
    ttc9 = gtk_button_new_with_label("TTC9");

    gtk_widget_set_name(ttc1,"ttc1");
    gtk_widget_set_name(ttc2,"ttc2");
    gtk_widget_set_name(ttc3,"ttc3");
    gtk_widget_set_name(ttc4,"ttc4");
    gtk_widget_set_name(ttc5,"ttc5");
    gtk_widget_set_name(ttc6,"ttc6");
    gtk_widget_set_name(ttc7,"ttc7");
    gtk_widget_set_name(ttc8,"ttc8");
    gtk_widget_set_name(ttc9,"ttc9");

    //adding image to button
    //gtk_button_set_always_show_image (GTK_BUTTON (ttc1), TRUE);
    //gtk_button_set_image(GTK_BUTTON(ttc1),image);


    gtk_grid_set_row_homogeneous(GTK_GRID(ttcgrid),TRUE);
    gtk_grid_attach(GTK_GRID(ttcgrid),GTK_BUTTON(ttc1),1,0,1,1);
    gtk_grid_attach(GTK_GRID(ttcgrid),GTK_BUTTON(ttc2),2,0,1,1);
    gtk_grid_attach(GTK_GRID(ttcgrid),GTK_BUTTON(ttc3),3,0,1,1);
    gtk_grid_attach(GTK_GRID(ttcgrid),GTK_BUTTON(ttc4),1,1,1,1);
    gtk_grid_attach(GTK_GRID(ttcgrid),GTK_BUTTON(ttc5),2,1,1,1);
    gtk_grid_attach(GTK_GRID(ttcgrid),GTK_BUTTON(ttc6),3,1,1,1);
    gtk_grid_attach(GTK_GRID(ttcgrid),GTK_BUTTON(ttc7),1,2,1,1);
    gtk_grid_attach(GTK_GRID(ttcgrid),GTK_BUTTON(ttc8),2,2,1,1);
    gtk_grid_attach(GTK_GRID(ttcgrid),GTK_BUTTON(ttc9),3,2,1,1);




    //Moving elements
    gtk_fixed_move(GTK_FIXED(fixedMainMenu),ttcpage,250,120);
    gtk_fixed_move(GTK_FIXED(boxPvP),player_vs_player,300,50);
    gtk_fixed_move(GTK_FIXED(boxPvP),player_vs_computer_easy,300,100);
    gtk_fixed_move(GTK_FIXED(boxPvP),player_vs_computer_medium,300,150);
    gtk_fixed_move(GTK_FIXED(boxPvP),player_vs_computer_hard,300,200);
    gtk_fixed_move(GTK_FIXED(boxPvP),quit,300,250);
     
    

    



    GtkCssProvider *cssProvider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssProvider, "theme.css", NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),GTK_STYLE_PROVIDER(cssProvider),GTK_STYLE_PROVIDER_PRIORITY_USER);
    
  
    g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_widget_show_all(window);
   //gtk_widget_hide(boxPvP);
    gtk_widget_hide(ttcpage);

    g_signal_connect(player_vs_player,"clicked", G_CALLBACK(hideMenu),NULL);
    //gtk code comes here
    gtk_main();

    return 0;
    
}

void hideMenu(){
        gtk_widget_hide(boxPvP);
        gtk_widget_show(ttcpage);
}