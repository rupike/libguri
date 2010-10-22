#include <stdlib.h>
#include <stddef.h>

/* TODO:
 * Component Recomposition
 * http://tools.ietf.org/html/rfc3986#section-5.3
 * Relative Resolution
 * http://tools.ietf.org/html/rfc3986#section-5.2
 * Normalization and Comparision
 * http://tools.ietf.org/html/rfc3986#section-6
 */

#ifdef URI_USE_GLIB
#include <glib.h>
#endif

typedef struct uri {
#ifdef URI_USE_GLIB
  GStringChunk *chunk;
#endif
  char *scheme;
  char *userinfo;
  char *host;
  char *path;
  char *query;
  char *fragment;
  unsigned int port;
} uri;

extern void uri_init(uri *u);
extern int uri_parse(uri *u, const char *buf, size_t len, const char **error_at);
extern void uri_clear(uri *u);
extern void uri_free(uri *u);

extern void uri_set_scheme(uri *u, const char *s, ssize_t l);
extern void uri_set_userinfo(uri *u, const char *s, ssize_t l);
extern void uri_set_host(uri *u, const char *s, ssize_t l);
extern void uri_set_path(uri *u, const char *s, ssize_t l);
extern void uri_set_query(uri *u, const char *s, ssize_t l);
extern void uri_set_fragment(uri *u, const char *s, ssize_t l);

extern void uri_normalize(uri *u);
extern char *uri_compose(uri *u);
extern void uri_transform(uri *base, uri *relative, uri *transformed);
