#!/usr/bin/env python

# example base.py

import pygtk
pygtk.require('2.0')
import gtk

class Base:
    def __init__(self):
        self.window = gtk.Window(gtk.WINDOW_TOPLEVEL)
        self.window.show()
        self.window.set_title("Ringo Text")
        self.window.resize(640,480)
        self.window.set_position(gtk.WIN_POS_CENTER)
        vbox = gtk.VBox(False, 0)
        hbox = gtk.HBox(False, 0)
        fixed = gtk.Fixed()
        vbox.add(hbox)
        self.window.add(vbox)
        #Add Button
        image = gtk.Image()
        image.set_from_stock(gtk.STOCK_ADD, gtk.ICON_SIZE_BUTTON)
        self.button = gtk.Button()
        self.button.set_image(image)
        hbox.add(self.button)
        image = gtk.Image()
        image.set_from_stock(gtk.STOCK_CLOSE, gtk.ICON_SIZE_BUTTON)
        self.button = gtk.Button()
        self.button.set_image(image)
        hbox.add(self.button)
        #Save Button
        image = gtk.Image()
        image.set_from_stock(gtk.STOCK_FLOPPY, gtk.ICON_SIZE_BUTTON)
        self.button = gtk.Button()
        self.button.set_image(image)
        hbox.add(self.button)
        #About Button
        image = gtk.Image()
        image.set_from_stock(gtk.STOCK_ABOUT, gtk.ICON_SIZE_BUTTON)
        self.button = gtk.Button()
        self.button.set_image(image)
        self.button.connect("clicked", self.on_clicked)
        
        hbox.add(self.button)
        self.textview =  gtk.TextView(buffer=None)
        vbox.add(self.textview)
        
        
        menubar = gtk.MenuBar()
        
        menu_file = gtk.Menu()
        menu_edit = gtk.Menu()
        menu_help = gtk.Menu()
        
        item_open = gtk.MenuItem("Open")
        item_open.connect("activate", self.on_open)
        item_save = gtk.MenuItem("Save")
        item_quit = gtk.MenuItem("Quit")
        menu_file.append(item_open)
        menu_file.append(item_save)
        menu_file.append(item_quit)

        item_cut = gtk.MenuItem("Cut")
        item_copy = gtk.MenuItem("Copy")
        item_paste = gtk.MenuItem("Paste")
        menu_edit.append(item_cut)
        menu_edit.append(item_copy)
        menu_edit.append(item_paste)
        
        item_about = gtk.MenuItem("About")
        menu_help.append(item_about)
        item_about.connect("activate", self.on_clicked)
        
        item_file = gtk.MenuItem("File")
        item_edit = gtk.MenuItem("Edit")
        item_help = gtk.MenuItem("Help")
        
        item_file.set_submenu(menu_file)
        item_edit.set_submenu(menu_edit)
        item_help.set_submenu(menu_help)
        
        menubar.append(item_file)
        menubar.append(item_edit)
        menubar.append(item_help)
        vbox.add(menubar)
        
        self.window.show_all()
        # About Message
    def on_clicked(self, widget):
        about = gtk.AboutDialog()
        about.set_program_name("Ringo Text Editor")
        about.set_version("0.01")
        about.set_copyright("(c) Alliace Team")
        about.set_comments("This is a very light notepad for Win and Linux")
        about.set_website("http://alliace.unterblog.ru")
        about.set_logo(gtk.gdk.pixbuf_new_from_file("battery.png"))
        about.run()
        about.destroy()                       
    def on_open(self, widget):
        dialog = gtk.FileChooserDialog("Open file in RTE",
                               None,
                               gtk.FILE_CHOOSER_ACTION_OPEN,
                               (gtk.STOCK_CANCEL, gtk.RESPONSE_CANCEL,
                                gtk.STOCK_OPEN, gtk.RESPONSE_OK))
        dialog.set_default_response(gtk.RESPONSE_OK)
        response = dialog.run()
        if response == gtk.RESPONSE_OK:
            print dialog.get_filename()
        elif response == gtk.RESPONSE_CANCEL:
            print 'Closed, no files selected'
        dialog.destroy()
    def main(self):
        gtk.main()

print __name__
if __name__ == "__main__":
    base = Base()
    base.main()
