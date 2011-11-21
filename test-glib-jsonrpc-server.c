#include <stdio.h>
#include <stdlib.h>
#include "glib-jsonrpc-server.h"

int cmd_ping(GLibJsonRpcServer *server,
             const char *method,
             JsonNode *params,
             JsonNode **response,
             gpointer user_data)
{
  printf("pong!\n");

  *response = json_node_new(JSON_NODE_VALUE);
  json_node_set_string(*response, "pong");
  
  return 0;
}

int cmd_fail(GLibJsonRpcServer *server,
             const char *method,
             JsonNode *params,
             JsonNode **response,
             gpointer user_data)
{
  printf("pong!\n");

  *response = json_node_new(JSON_NODE_VALUE);
  json_node_set_string(*response, "Lupchi is black and white!");
  
  return -42;
}
int cmd_echo(GLibJsonRpcServer *server,
             const char *method,
             JsonNode *params,
             JsonNode **response,
             gpointer user_data)
{
  printf("echo!\n");

  JsonReader *reader = json_reader_new(params);
  
  // Assume array at the moment
  json_reader_read_element(reader, 0);
  const char *param_string = json_reader_get_string_value(reader);
  g_object_unref(reader);

  // echo the response
  *response = json_node_new(JSON_NODE_VALUE);
  json_node_set_string(*response, param_string);
  
  return 0;
}

// Global variables for this test only
gboolean async_pong(gpointer data)
{
  GLibJsonRpcServer *server = (GLibJsonRpcServer*)data;
  JsonNode *response = json_node_new(JSON_NODE_VALUE);
  json_node_set_string(response, "async_pong");

  glib_jsonrpc_server_send_async_response(server,
                                          response);
  return 0;
}

int cmd_async_ping(GLibJsonRpcServer *server,
                   const char *method,
                   JsonNode *params,
                   gpointer user_data)
{
  g_timeout_add_seconds(2, async_pong, server);

  return 0;
}

int main(int argc, char **argv)
{
  g_type_init ();

  GLibJsonRpcServer *server = glib_jsonrpc_server_new(8123);

  glib_jsonrpc_server_register_command(server,
                                       "ping",
                                       cmd_ping,
                                       NULL);

  glib_jsonrpc_server_register_command(server,
                                       "echo",
                                       cmd_echo,
                                       NULL);

  glib_jsonrpc_server_register_command(server,
                                       "fail",
                                       cmd_fail,
                                       NULL);

  glib_jsonrpc_server_register_async_command(server,
                                             "async_ping",
                                             cmd_async_ping,
                                             NULL);

  g_main_loop_run (g_main_loop_new (NULL, FALSE));

  exit(0);
}