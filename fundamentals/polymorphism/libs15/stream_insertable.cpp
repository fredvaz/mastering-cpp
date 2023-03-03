#include "stream_insertable.hpp"

//

std::ostream& operator<< (std::ostream& out,const StreamInsertable& operand){
    operand.stream_insert(out);
    return out;
}
