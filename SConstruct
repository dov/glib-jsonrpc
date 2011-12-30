import glob

env = Environment(CPPFLAGS=['-Wall','-g'])
env.ParseConfig('pkg-config --cflags --libs gio-2.0 json-glib-1.0')

lib = env.Library("glib-jsonrpc",
                  ["glib-jsonrpc-server.c",
                   "glib-jsonrpc-client.c",
                   "glib-jsonrpc-json.c"])

env.Program("test-glib-jsonrpc-server",
            ["test-glib-jsonrpc-server.c"],
            LIBS = lib + env['LIBS'])

env.Program("test-glib-jsonrpc-client",
            ["test-glib-jsonrpc-client.c"],
            LIBS = lib + env['LIBS'])


