#include <stdlib.h>
#include <gtk/gtk.h>


int opened = 0;
char opened_text[12000];

static void authors_call (GtkWidget *wid, GtkWidget *win)
{
  GtkWidget *dialog = NULL;

  dialog = gtk_message_dialog_new (GTK_WINDOW (win), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "Ringo Text Editor and others products Ringo - powered by \n Alliace Team. Coder and CEO: Musicfuns \n 2013 - 2014 years \n GPL License");
  gtk_window_set_position (GTK_WINDOW (dialog), GTK_WIN_POS_CENTER);
  gtk_dialog_run (GTK_DIALOG (dialog));
  gtk_widget_destroy (dialog);
}
static void open_web_site()
{
system("gnome-open http://ringo.unterblog.ru");

}
static void open_file(GtkWidget *wid, GtkWidget *win)
{
    GtkWidget *dialog;

dialog = gtk_file_chooser_dialog_new ("Open Text File in Ringo Text Editor",
                                       NULL,
                                      GTK_FILE_CHOOSER_ACTION_OPEN,
                                      GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
                                      GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
                                      NULL);
gtk_dialog_run (GTK_DIALOG (dialog));
char *filename;


    filename = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
     FILE * f = fopen(filename,"r");
     fscanf(f, "%s", opened_text);
     opened = 1;
}

int main (int argc, char *argv[])
{
  GtkWidget *win = NULL;

  GtkWidget *textarea = NULL;
  GtkWidget *vbox;
  GtkWidget *menubar;
  GtkWidget *filemenu;
  GtkWidget *file;
  GtkWidget *quit;
  GtkWidget *help;
  GtkWidget *helpmenu;
  GtkWidget *author;
  GtkWidget *website;
  GtkWidget *open;
  GtkWidget *save;
  GtkWidget *save_as;
  GtkWidget *close;
   /* Initialize GTK+ */
  g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, (GLogFunc) gtk_false, NULL);
  gtk_init (&argc, &argv);
  g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, g_log_default_handler, NULL);

 // Create a Window
  win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_container_set_border_width (GTK_CONTAINER (win), 8);
  gtk_window_set_title (GTK_WINDOW (win), "Ringo Text Editor");
  gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
  gtk_widget_realize (win);
  g_signal_connect (win, "destroy", gtk_main_quit, NULL);
  gtk_window_set_default_size(GTK_WINDOW(win),640,480);



   //create a text box
 vbox = gtk_vbox_new(FALSE, 0);
  gtk_container_add(GTK_CONTAINER(win), vbox);


  textarea =  gtk_text_view_new ();
  gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(textarea),GTK_WRAP_WORD);
   gtk_box_pack_start (GTK_BOX (vbox), textarea, TRUE, TRUE, 0);




  menubar = gtk_menu_bar_new();
  filemenu = gtk_menu_new();
  helpmenu = gtk_menu_new();

  file = gtk_menu_item_new_with_label("File");
  open = gtk_menu_item_new_with_label("Open");
  save = gtk_menu_item_new_with_label("Save");
  close = gtk_menu_item_new_with_label("Close");
  save_as = gtk_menu_item_new_with_label("Save as..");
  quit = gtk_menu_item_new_with_label("Quit");
  help = gtk_menu_item_new_with_label("Help");
  author = gtk_menu_item_new_with_label("Authors");
  website = gtk_menu_item_new_with_label("Official Web Site");

// Меню файлов
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(file), filemenu);
  gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), open);
  gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), close);
  gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), save);
  gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), save_as);
  gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), quit);

  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), file);
  //Help Menu


  gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
  gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), author);
  gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), website);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);


  //Connect
  gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 3);

    g_signal_connect(G_OBJECT(quit), "activate",
        G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(author), "activate",
        G_CALLBACK(authors_call), NULL);
    g_signal_connect(G_OBJECT(website), "activate",
        G_CALLBACK(open_web_site), NULL);
    g_signal_connect(G_OBJECT(open), "activate",
        G_CALLBACK(open_file),NULL);



 // Открытие файла передача в переменную
 if (opened == 1)
 {

 }


 //вроде конец
  gtk_widget_show_all (win);
  gtk_main ();
  return 0;
}
