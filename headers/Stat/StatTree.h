#ifndef TREE
#define TREE
    #include "../Abstract/Tree.h" 
#endif

#ifndef STATNODE
#define STATNODE
    #include "StatNode.h"
#endif

#ifndef MEMORY
#define MEMORY
    #include <memory>
#endif

#ifndef QUEUE
#define QUEUE
    #include <queue>
#endif

#ifndef FSTREAM
#define FSTREAM
    #include <fstream>
#endif

class StatTree final : public Tree
{
public:
        
    enum Mode {Encrypt, Decrypt}; // mode of object

    // constructors
    StatTree(const StatTree& str);                                       // copy construct
    StatTree(StatTree&& str);                                            // move construct
    StatTree(const std::string& Name_of_File, const StatTree::Mode& md); // encr file
    explicit StatTree(const std::vector<char>& bytes);                   // encr vector
    StatTree(const std::vector<char>& tree_in_vec,
             unsigned int Num_diff_bytes, unsigned int Freq_length);     // decr inf


    // change tree (may be helpful if there is bad_state = true)
    bool make_trf(const std::string& nof);                           // make tr from file
    bool read_trf(const std::string& nof, const StatTree::Mode& md); // read tr from file
    bool make_trv(const std::vector<char>& bytes);                   // make tr from vect
    bool read_trv(const std::vector<char>& tree, int flength,
                  int ndif_b, const StatTree::Mode& md);             // read tr from vect
    
    // get properties
    const std::string&                     get_interacting_nf() const;
    const StatTree::Mode&                  get_mode()           const;
    std::vector<char>                      get_tree_in_vec()    const;
    const std::shared_ptr<const StatNode>& get_curr()           const;
    unsigned int                           get_num_diff_bytes() const;
    unsigned int                           get_freq_length()    const;

    // move in tree and view
    bool            move_left()           override;
    bool            move_right()          override;
    void            move_to_root()        override;
    unsigned short  get_curr_byte() const override;
    std::size_t     get_curr_freq() const override;

    // state flags of object
    bool is_inf_empty()         const;
    bool is_bad_state()         const;
    bool is_success_file_open() const;
    bool is_bad_tree()          const;

    // operators of assignment
    StatTree& operator = (const StatTree& str); // copy operator
    StatTree& operator = (StatTree&& str);      // move operator

    // decryption
    std::vector<char> decrypt(const std::vector<char>& bytes_to_decrypt)      override;
    std::vector<char> decrypt_bits(const std::pair<char, unsigned int>& bits) override;

    ~StatTree() override; // virtual destructor

protected:

    void do_copy(const StatTree& str);
    void do_move(StatTree&& str);

    void copy_curr_node(const std::pair<std::size_t, unsigned int>& route,
                        std::shared_ptr<const StatNode>& curr_node);

    // read tree from file
    bool read_tree_file(std::priority_queue<std::shared_ptr<StatNode>,
                                            std::vector<std::shared_ptr<StatNode>>,
                                            StatNode::ptr_compare>& StatNodes);
    // read tree from vector
    bool read_tree_vec(const std::vector<char>& tree,
                       std::priority_queue<std::shared_ptr<StatNode>,
                                           std::vector<std::shared_ptr<StatNode>>,
                                           StatNode::ptr_compare>& StatNodes);

    bool make_tree_file(const std::string& nof,
                        std::priority_queue<std::shared_ptr<StatNode>,
                                            std::vector<std::shared_ptr<StatNode>>,
                                            StatNode::ptr_compare>& StatNodes);

    bool make_tree_vec(const std::vector<char>& bytes,
                       std::priority_queue<std::shared_ptr<StatNode>,
                                           std::vector<std::shared_ptr<StatNode>>,
                                           StatNode::ptr_compare>& StatNodes);

    // make tree from nodes with Hafman algorithm
    void make_tree(std::priority_queue<std::shared_ptr<StatNode>,
                                       std::vector<std::shared_ptr<StatNode>>,
                                       StatNode::ptr_compare>& StatNodes);

    void clear_all_data(); // clear data from tree

    // properties
    static const unsigned int            sz_byte_fq_tab = 256;
    std::shared_ptr<StatNode>            root;
    std::shared_ptr<const StatNode>      curr_node_prot;
    std::shared_ptr<const StatNode>      curr_node_pub;
    std::pair<std::size_t, unsigned int> route_curr_prot;
    std::pair<std::size_t, unsigned int> route_curr_pub;
    std::vector<std::size_t>             Byte_Freq;
    std::string                          interacting_nf;
    StatTree::Mode                       mode;
    unsigned int                         freq_length;
    unsigned int                         num_diff_bytes;
    bool                                 bad_state;
    bool                                 success_file_open;
    bool                                 inf_is_empty;
    bool                                 bad_tree;
};
