/* test-glib-jsonrpc-client.c: A test program for the Json RCP client in glib.
 *
 * Copyright (C) 2011 Dov Grobgeld <dov.grobgeld@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */
#include <stdlib.h>
#include "glib-jsonrpc-client.h"
#include "glib-jsonrpc-json.h"
#include <stdio.h>

int main(int argc, char **argv)
{
  g_type_init ();

  GLibJsonRpcClient *client = glib_jsonrpc_client_new("localhost",8123);
  JsonNode *params = glib_jsonrpc_json_csv_to_json_array("hello!");

  JsonNode *response;
  glib_jsonrpc_client_call(client,
                           "echo",
                           params,
                           // output
                           &response);
  json_node_free(params);

  printf("response: %s\n", glib_jsonrpc_json_to_string(response));
  
  exit(0);
}    
