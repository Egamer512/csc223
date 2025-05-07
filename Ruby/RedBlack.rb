class RBNode
  attr_accessor :value, :left, :right, :color

  RED = :red
  BLACK = :black

  def initialize(value, color = RED)
    @value = value
    @left = nil
    @right = nil
    @color = color
  end

  def c_red?
    @color == RED
  end
end

class RedBlackTree
  attr_accessor :root_node

  def initialize
    @root_node = nil
  end

  def insert(value)
    @root_node = insert_recursive(@root_node, value)
    @root_node.color = RBNode::BLACK
  end

  def insert_recursive(node, value)
    return RBNode.new(value) if node.nil?

    if value < node.value
      node.left = insert_recursive(node.left, value)
    else
      node.right = insert_recursive(node.right, value)
    end

    node = rotate_left(node) if red?(node.right) && !red?(node.left)
    node = rotate_right(node) if red?(node.left) && red?(node.left&.left)
    flip_colors(node) if red?(node.left) && red?(node.right)

    node
  end

  def red?(node)
    node&.c_red?
  end

  def rotate_left(h)
    x = h.right
    h.right = x.left
    x.left = h
    x.color = h.color
    h.color = RBNode::RED
    x
  end

  def rotate_right(h)
    x = h.left
    h.left = x.right
    x.right = h
    x.color = h.color
    h.color = RBNode::RED
    x
  end

  def flip_colors(h)
    h.color = RBNode::RED
    h.left.color = RBNode::BLACK
    h.right.color = RBNode::BLACK
  end

  def delete(value)
    @root_node = delete_recursive(@root_node, value)
    @root_node.color = RBNode::BLACK if @root_node
  end

  def delete_recursive(node, value)
    return node if node.nil?

    if value < node.value
      node.left = delete_recursive(node.left, value)
    elsif value > node.value
      node.right = delete_recursive(node.right, value)
    else
      # Node with one child or no children
      if node.left.nil? || node.right.nil?
        return node.left || node.right
      end

      # Node with two children
      successor = min(node.right)
      node.value = successor.value
      node.right = delete_recursive(node.right, successor.value)
    end

    node = balance_after_deletion(node)
    node
  end

  def balance_after_deletion(node)
    # Balance cases
    if red?(node.right)
      node = rotate_left(node)
    end
    if red?(node.left) && !red?(node.left.left)
      node = rotate_right(node)
    end
    if red?(node.left) && red?(node.left.left)
      flip_colors(node)
    end
    node
  end

  def min(node)
    while node.left
      node = node.left
    end
    node
  end

  # Credit to ChatGPT for creating visualization
  def visualize(node = @root_node)
    lines = build_lines(node)
    lines.each { |line| puts line }
    puts "\n\n"
  end
end

def print_tree(node, left_accessor: nil, right_accessor: nil, value_accessor: nil, prefix: "", is_left: true)
  return if node.nil?

  left_accessor  ||= -> (n) { n.left }
  right_accessor ||= -> (n) { n.right }
  value_accessor ||= -> (n) { "#{n.value}(#{n.color==RBNode::RED ? 'R': 'B'})"} 

  right_child = right_accessor.call(node)
  left_child  = left_accessor.call(node)

  print_tree(right_child, left_accessor: left_accessor, right_accessor: right_accessor,
             value_accessor: value_accessor,
             prefix: prefix + (is_left ? "│   " : "    "), is_left: false)

  puts prefix + (is_left ? "└── " : "┌── ") + value_accessor.call(node)

  print_tree(left_child, left_accessor: left_accessor, right_accessor: right_accessor,
             value_accessor: value_accessor,
             prefix: prefix + (is_left ? "    " : "│   "), is_left: true)
end

# Sample usage
tree = RedBlackTree.new
[6, 9, 4, 8, 23, 28, 47, 12, 325, 2356, 7547, 12, 5326, 745].each { |val| tree.insert(val) }

print_tree(tree.root_node)
