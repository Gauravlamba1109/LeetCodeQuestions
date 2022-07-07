// If node is not found in any possible path,
// Then return false
return false;
}
string getDirections(TreeNode* root, int startValue, int destValue) {
// Get LCA of start and destination node
TreeNode* lca = getLCA(root, startValue, destValue);
string lca_to_start = "", lca_to_dest = "";
// Then find path from LCA to start
// as well as path from LCA to destination
traverse(lca, lca_to_start, startValue);
traverse(lca, lca_to_dest, destValue);
// Since we need to move upward from start till LCA,
// Thus, convert all characters in lca_to_start path to 'U'
for(auto& c : lca_to_start) c = 'U';
// Concatenate both paths, to get shortest path from
// Start node -> Destination node.
return lca_to_start + lca_to_dest;
}
};
```