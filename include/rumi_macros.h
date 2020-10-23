#ifndef RUMI_MACROS_H
#define RUMI_MACROS_H

#define RUMI_NEW(x) Rumi rumi = rumi_new(x);
#define RUMI_DELETE(x) rumi = rumi_delete(rumi);

#define RUMI_OK(...) rumi_ok(rumi, __VA_ARGS__)



#endif