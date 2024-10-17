#include "sql/executor/drop_table_executor.h"

#include "common/log/log.h"
#include "event/session_event.h"
#include "event/sql_event.h"
#include "session/session.h"
#include "sql/stmt/drop_table_stmt.h"
#include "storage/db/db.h"

RC DropTableExecutor::execute(SQLStageEvent *sql_event)
{
  DropTableStmt *stmt = (DropTableStmt *)sql_event->stmt();
  Db *db = sql_event->session_event()->session()->get_current_db();
  return db->drop_table(stmt->table_name().c_str()); 
}