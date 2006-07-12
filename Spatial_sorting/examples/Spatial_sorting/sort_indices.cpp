
#include <CGAL/Simple_cartesian.h>
#include <CGAL/spatial_sort.h>


typedef CGAL::Simple_cartesian<double> K;
typedef K::Point_2 Point_2;
typedef std::vector<Point_2>::iterator Point_iterator;



template <typename Kernel, typename Iterator>
struct Sort_traits_2 {

  typedef Iterator Point_2;

  struct Less_x_2 {
    bool operator() (const Point_2 &p, const Point_2 &q) const
    { 
      K k;
      std::cout << "compare " << *p << "  and " << *q << std::endl;
      return k.less_x_2_object() (*p, *q);
    } 
  };

  Less_x_2
  less_x_2_object() const
  {
    return Less_x_2();
  }
  
  struct Less_y_2 {
    bool operator() (const Point_2 &p, const Point_2 &q) const
    { 
      K k;
      return k.less_y_2_object() (*p, *q);
    } 
  };


  Less_y_2
  less_y_2_object() const
  {
    return Less_y_2();
  }
};


typedef CGAL::Hilbert_sort_2<Sort_traits_2<K, Point_iterator> > Hilbert_sort_2;
typedef CGAL::Multiscale_sort<Hilbert_sort_2> Spatial_sort_2;




int main ()
{
  Spatial_sort_2 sort_2;

  std::vector<Point_2> points;
  std::vector<Point_iterator> iterators;

  Point_2 p;
  while(std::cin >> p){
    points.push_back(p);
  }

  iterators.reserve(points.size());
  for(Point_iterator it = points.begin(); it != points.end(); ++it){
    iterators.push_back(it);
  }

  sort_2(iterators.begin(), iterators.end());

  for(int i = 0; i < iterators.size(); i++){
    std::cout << *iterators[i] << std::endl;
  }

  std::cout << "done" << std::endl;

  return 0;
}
