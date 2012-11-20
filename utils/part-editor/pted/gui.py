#
# gui.py
#

import sys
import gtk


class Handler:
    def ped_exit(self, *args):
        gtk.main_quit(*args);
    
    def on_part_editor_window_delete_event(self, *args):
        gtk.main_quit(*args);

class Gui:
    def __init__(self):
        self.builder = gtk.Builder()
        self.builder.add_from_file("res/part-editor.glade")
        self.builder.connect_signals(Handler())
        
        
        
        editor_window = self.builder.get_object("part_editor_window")
        editor_window.show_all()
        
    
    def add_computed_props(self):
        
        gui_proplist = self.builder.get_object("computed_props")
        
        prop_item = gui_proplist.append(["mass", 12.3])
        
        #gui_proplist.show_all()
        
        return prop_item
    
    
    def load_classes
        
        
pted_gui = Gui()
gtk.main()
