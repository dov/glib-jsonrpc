//======================================================================
//  glib-json-rpc-server.h - 
//
//  Dov Grobgeld <dov.grobgeld@gmail.com>
//  Wed Nov 16 21:02:37 2011
//----------------------------------------------------------------------
#ifndef GLIB_JSON_RPC_SERVER_H
#define GLIB_JSON_RPC_SERVER_H

#include "json-glib/json-glib.h"

typedef struct {
} GLibJsonRpcServer; 

typedef int (GLibJsonRpcCommandCallback)(GLibJsonRpcServer *server,
                                         const char *method,
                                         JsonNode *params,
                                         JsonNode **response,
                                         gpointer user_data);

typedef int (GLibJsonRpcCommandAsyncCallback)(GLibJsonRpcServer *server,
                                              const char *method,
                                              JsonNode *params,
                                              gpointer user_data);

GLibJsonRpcServer *glib_jsonrpc_server_new(int port);

int glib_jsonrpc_server_register_command(GLibJsonRpcServer *jsonrpc_server,
                                         const gchar *command,
                                         GLibJsonRpcCommandCallback *callback,
                                         gpointer user_data);

int glib_jsonrpc_server_register_async_command(GLibJsonRpcServer *jsonrpc_server,
                                               const gchar *command,
                                               GLibJsonRpcCommandAsyncCallback *async_callback,
                                               gpointer user_data);
// The json node ownershap is transfered.
int  glib_jsonrpc_server_send_async_response(GLibJsonRpcServer *server,
                                             JsonNode *response);


#endif /* GLIB-JSON-RPC-SERVER */
