import glob

env = Environment(CPPFLAGS=['-Wall','-g'])
env.ParseConfig('pkg-config --cflags --libs gio-2.0 json-glib-1.0')

env.Program("test-glib-jsonrpc-server",
            ["test-glib-jsonrpc-server.c",
             "glib-jsonrpc-server.c"])


