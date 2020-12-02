#if !defined(GRAPH_HH)
#define GRAPH_HH

#include <tuple>
#include <thread>
#include <chrono>
#include <QString>

class vis
{
private:
    using weight_t  = int;
    using node_id_t = uint64_t;
    struct weighted_gragh_t
    {
        weight_t    w;
        node_id_t   link[2];
    };
    weighted_gragh_t    result;
    weighted_gragh_t    input;
    bool ready;
    QString comment;
    void wait_for_invitation()
    {
        while (!ready)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
public:
    vis();
    void visualize();
    QString get_comment();

};

#endif // GRAPH_HH
