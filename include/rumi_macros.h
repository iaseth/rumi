#ifndef RUMI_MACROS_H
#define RUMI_MACROS_H

#define RUMI_NEW(x)          Rumi rumi = rumi_new(x)
#define RUMI_DELETE(x)       rumi = rumi_delete(rumi)

#define RUMI_OK(...)         rumi_ok(rumi, __VA_ARGS__)
#define RUMI_ERROR(...)      rumi_error(rumi, __VA_ARGS__)

#define RUMI_SUGGEST(...)    rumi_suggest(rumi, __VA_ARGS__)
#define RUMI_TIP(...)        rumi_tip(rumi, __VA_ARGS__)
#define RUMI_WARN(...)       rumi_warn(rumi, __VA_ARGS__)

#define RUMI_GOOD(...)       rumi_good(rumi, __VA_ARGS__)
#define RUMI_BAD(...)        rumi_bad(rumi, __VA_ARGS__)

#define RUMI_NATE(...)       rumi_nate(rumi, __VA_ARGS__)



#endif