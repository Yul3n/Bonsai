#include "config.h"
#include <stdlib.h>
#include <string.h>

struct leaf {
	char *name;
	struct leaf *nodes;
	int len; 
	struct leaf *pred;
};

struct leaf 
add_node (struct leaf n, char *name)
{
	if (n.len) 
		n.nodes = realloc(n.nodes, sizeof(struct leaf) * (n.len + 1));
	else {
		n.nodes = malloc(sizeof(struct leaf));
		n.len   = 0;
	}
	n.len ++;
	n.nodes       += n.len;
	n.nodes->len  = 0;
	n.nodes->name = name;
	n.pred        = &n;
	return n;
}

int
total_len (struct leaf n)
{
	int len = 0;
	for (int i = 0; i < n.len; i++)
		len += 1 + total_len(*(n.nodes + i));
	return len;
}

struct leaf
vmove_node (struct leaf n, int i)
{
}
