#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria    *inv[4];
    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(const MateriaSource &src);
        MateriaSource &operator=(const MateriaSource &src);

        void    learnMateria(AMateria* m);
        AMateria* createMateria(std::string const & type);
};

#endif
