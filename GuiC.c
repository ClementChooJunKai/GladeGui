#include <gtk/gtk.h>
#include <string.h>

GtkWidget *window;
GtkWidget *mainMenu;
GtkWidget *player_vs_player;
GtkWidget *player_vs_computer_easy;
GtkWidget *player_vs_computer_medium;
GtkWidget *player_vs_computer_hard;
GtkWidget *quit;
GtkWidget *fixed;
GtkWidget *tttpage;
GtkWidget *tttgrid;
GtkWidget *ttt1;
GtkWidget *child1;
GtkWidget *ttt2;
GtkWidget *ttt3;
GtkWidget *ttt4;
GtkWidget *ttt5;
GtkWidget *ttt6;
GtkWidget *ttt7;
GtkWidget *ttt8;
GtkWidget *ttt9;
GtkWidget *image;
GtkWidget *player1;
GtkWidget *player2;
GtkWidget *score1;
GtkWidget *score2;
GtkWidget *header;

void hideMenu();
int main (int argc,char *argv[]){
    gtk_init(&argc,&argv);
  

    //Creating a window and styling of window
    window =gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"Tic Tac Toe");
    gtk_window_set_default_size(GTK_WINDOW(window),700,700);
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(window),FALSE);
    //gtk_window_set_decorated(GTK_WINDOW(window),FALSE);
    
    image = gtk_image_new_from_file ("download.jfif");


    //gtk_widget_show (fixed);
    //creating a fixed container
    fixed = gtk_fixed_new ();
    
    gtk_widget_set_name(fixed,"fixed");
    
    gtk_container_add (GTK_CONTAINER (window), fixed);
    
    //creating box container
    mainMenu = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
    //tttpage = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
    tttpage = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(fixed),mainMenu);
    
    gtk_container_add(GTK_CONTAINER (fixed), tttpage);
    gtk_widget_set_name(mainMenu,"mainMenu");
    gtk_widget_set_name(tttpage,"tttpage");
    
   
    
    //Main Menu
    //creating elements in main menu 
    player_vs_player = gtk_button_new_with_label("Player Vs Player");
    player_vs_computer_easy = gtk_button_new_with_label("Player Versus Computer(Easy)");
    player_vs_computer_medium = gtk_button_new_with_label("Player Versus Computer(Medium)");
    player_vs_computer_hard = gtk_button_new_with_label("Player Versus Computer(Hard)");

    quit= gtk_button_new_with_label("Quit");
    g_signal_connect(quit,"clicked", G_CALLBACK(gtk_main_quit),NULL);

    gtk_container_add(GTK_CONTAINER(mainMenu),player_vs_computer_easy);
    gtk_widget_set_name(player_vs_computer_easy,"player_vs_computer_easy");
    gtk_container_add(GTK_CONTAINER(mainMenu),player_vs_player);
    gtk_widget_set_name(player_vs_player,"player_vs_player");
    gtk_container_add(GTK_CONTAINER(mainMenu),quit);
    gtk_widget_set_name(quit,"quit");
    gtk_container_add(GTK_CONTAINER(mainMenu),player_vs_computer_hard);
    gtk_widget_set_name(player_vs_computer_hard,"player_vs_computer_hard");
    gtk_container_add(GTK_CONTAINER(mainMenu),player_vs_computer_medium);
    gtk_widget_set_name(player_vs_computer_medium,"player_vs_computer_medium");

    
    //Creating welcome page
    header = gtk_label_new("TIC TAC TOE");
    gtk_widget_set_name(header,"header");
    gtk_container_add(GTK_CONTAINER(fixed),header);

    //Creating player 1,2 label
    player1 = gtk_label_new("player1");
    player2 = gtk_label_new("player2");
    gtk_container_add(GTK_CONTAINER(tttpage),player1);
    gtk_container_add(GTK_CONTAINER(tttpage),player2);

    //Tic tac toe page 
    //creating elements in page ttt
    tttgrid = gtk_grid_new();
    gtk_widget_set_name(tttgrid,"tttgrid");
    gtk_container_add(GTK_CONTAINER(tttpage),tttgrid);
    

    ttt1 = gtk_button_new_with_label("ttt1");
    ttt2 = gtk_button_new_with_label("ttt2");
    ttt3 = gtk_button_new_with_label("ttt3");
    ttt4 = gtk_button_new_with_label("ttt4");
    ttt5 = gtk_button_new_with_label("ttt5");
    ttt6 = gtk_button_new_with_label("ttt6");
    ttt7 = gtk_button_new_with_label("ttt7");
    ttt8 = gtk_button_new_with_label("ttt8");
    ttt9 = gtk_button_new_with_label("ttt9");

    gtk_widget_set_name(ttt1,"ttt1");
    gtk_widget_set_name(ttt2,"ttt2");
    gtk_widget_set_name(ttt3,"ttt3");
    gtk_widget_set_name(ttt4,"ttt4");
    gtk_widget_set_name(ttt5,"ttt5");
    gtk_widget_set_name(ttt6,"ttt6");
    gtk_widget_set_name(ttt7,"ttt7");
    gtk_widget_set_name(ttt8,"ttt8");
    gtk_widget_set_name(ttt9,"ttt9");

    //adding image to button
    //gtk_button_set_always_show_image (GTK_BUTTON (ttt1), TRUE);
    //gtk_button_set_image(GTK_BUTTON(ttt1),image);


    gtk_grid_set_row_homogeneous(GTK_GRID(tttgrid),TRUE);
    gtk_grid_attach(GTK_GRID(tttgrid),GTK_BUTTON(ttt1),1,0,1,1);
    gtk_grid_attach(GTK_GRID(tttgrid),GTK_BUTTON(ttt2),2,0,1,1);
    gtk_grid_attach(GTK_GRID(tttgrid),GTK_BUTTON(ttt3),3,0,1,1);
    gtk_grid_attach(GTK_GRID(tttgrid),GTK_BUTTON(ttt4),1,1,1,1);
    gtk_grid_attach(GTK_GRID(tttgrid),GTK_BUTTON(ttt5),2,1,1,1);
    gtk_grid_attach(GTK_GRID(tttgrid),GTK_BUTTON(ttt6),3,1,1,1);
    gtk_grid_attach(GTK_GRID(tttgrid),GTK_BUTTON(ttt7),1,2,1,1);
    gtk_grid_attach(GTK_GRID(tttgrid),GTK_BUTTON(ttt8),2,2,1,1);
    gtk_grid_attach(GTK_GRID(tttgrid),GTK_BUTTON(ttt9),3,2,1,1);




    //Moving elements
    gtk_fixed_move(GTK_FIXED(fixed),tttpage,150,120);
    //gtk_fixed_move(GTK_FIXED(mainMenu),player_vs_player,300,50);
    //gtk_fixed_move(GTK_FIXED(mainMenu),player_vs_computer_easy,300,100);
    //gtk_fixed_move(GTK_FIXED(mainMenu),player_vs_computer_medium,300,150);
   // gtk_fixed_move(GTK_FIXED(mainMenu),player_vs_computer_hard,300,200);
   // gtk_fixed_move(GTK_FIXED(mainMenu),quit,300,250);



    gtk_fixed_move(GTK_FIXED(tttpage),player1,0,120);
    gtk_fixed_move(GTK_FIXED(tttpage),player2,50,120);
    gtk_fixed_move(GTK_FIXED(tttpage),tttgrid,100,120);  
    


    GtkCssProvider *cssProvider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssProvider, "theme.css", NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),GTK_STYLE_PROVIDER(cssProvider),GTK_STYLE_PROVIDER_PRIORITY_USER);
    
  
    g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_widget_show_all(window);
   //gtk_widget_hide(mainMenu);
    gtk_widget_hide(tttpage);

    g_signal_connect(player_vs_player,"clicked", G_CALLBACK(hideMenu),NULL);
    g_signal_connect(player_vs_computer_easy,"clicked", G_CALLBACK(hideMenu),NULL);
    g_signal_connect(player_vs_computer_medium,"clicked", G_CALLBACK(hideMenu),NULL);
    g_signal_connect(player_vs_computer_hard,"clicked", G_CALLBACK(hideMenu),NULL);


    //gtk code comes here
    gtk_main();

    return 0;
    
}

void hideMenu(){

        gtk_widget_hide(mainMenu);
        gtk_widget_show(tttpage);
}

