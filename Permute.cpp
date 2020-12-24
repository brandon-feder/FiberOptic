// Class to find every permutation of every length in range [1, n] where n is the parameter to the constructor
class IncreasingPermute
{
    public:
        // Vector with all the resulting permutations
        std::vector<std::vector<short>> perms;
        
        // The max of the range to find permutations of
        short N;
        
        // Constructor for class
        IncreasingPermute(short n) : IncreasingPermute(n, -1) {}

        IncreasingPermute(short n, short l)
        {
            // Setup initial variables
            N = n;
            std::vector<short> I_perm = {};
            std::vector<short> I_left;

            // Add values to the indecies left
            for(int i = 0; i < N; ++i)
                I_left.push_back(i);
            
            // Find the permutations
            findPerms(I_perm, I_left, l);
        }
    
    private:
        // Recursive function to find all the permutations
        void findPerms(std::vector<short> P, std::vector<short> L, short l)
        { 
            // For the index of every indecy left
            for(short i = 0; i < L.size(); ++i)
            {
                // Setup the new permutation and indecie left vector
                std::vector<short> Np = P;
                std::vector<short> Nl = L;

                // Add/remove from new vectors
                Np.push_back(L[i]);
                Nl.erase(Nl.begin()+i);

                // Optimization To Only Get Increasing

                if(std::is_sorted(Np.begin(), Np.end()))
                {
                    // printShortVec(Np);
                    // std::cout << l << std::endl;
                    // std::cout << (Np.size() < l || l == -1) << " " << (Np.size() == l || l == -1) << std::endl;
                    // std::cout << "--------------------" << std::endl;

                    if(Np.size() < l || l == -1)
                        findPerms(Np, Nl, l); // Recursevly find mire permutations
                    
                    if(Np.size() == l || l == -1)
                    {
                        printShortVec(Np);
                        perms.push_back(Np); // Add permutation found to perm array
                    }
                }
            }
        }
};