//
// Created by jhwangbo on 18. 1. 1.
//

#ifndef RAICOMMON_RAI_MESSAGE_HPP
#define RAICOMMON_RAI_MESSAGE_HPP
#include "rai_message_logger.hpp"

#define RAIMSG(msg, severity) { std::stringstream raimessagestream; \
                                raimessagestream<<msg; \
                                rai::RaiMsg().stream(__FILE__, __LINE__, raimessagestream, severity); }

#define RAIINFO(msg) RAIMSG(msg, rai::RSEVERITY_INFO)
#define RAIWARN(msg) RAIMSG(msg, rai::RSEVERITY_WARN)
#define RAIFATAL(msg) RAIMSG(msg, rai::RSEVERITY_FATAL)

#define RAIINFO_IF(con, msg) if(con) RAIMSG(msg, rai::RSEVERITY_INFO)
#define RAIWARN_IF(con, msg) if(con) RAIMSG(msg, rai::RSEVERITY_WARN)
#define RAIFATAL_IF(con, msg) if(con) RAIMSG(msg, rai::RSEVERITY_FATAL)

#define RAIASSERT(con, msg) if(!(con)) RAIMSG(msg, rai::RSEVERITY_FATAL)

#ifdef RAIDEBUG
  #define DRAIINFO(msg) RAIINFO(msg)
  #define DRAIWARN(msg) RAIIWARN(msg)
  #define DRAIFATAL(msg) RAIFATAL(msg)

  #define DRAIINFO_IF(con, msg) RAIINFO_IF(con, msg)
  #define DRAIWARN_IF(con, msg) RAIIWARN_IF(con, msg)
  #define DRAIFATAL_IF(con, msg) RAIFATAL_IF(con, msg)

  #define DRAIASSERT(con, msg) RAIASSERT(con, msg)
#else
  #define DRAIINFO(msg)
  #define DRAIWARN(msg)
  #define DRAIFATAL(msg)

  #define DRAIINFO_IF(con, msg)
  #define DRAIWARN_IF(con, msg)
  #define DRAIFATAL_IF(con, msg)

  #define DRAIASSERT(con, msg)
#endif

#endif //RAICOMMON_RAI_MESSAGE_HPP