#include "basebag.h"
// ! Nội dung task cũ cần bỏ vào (chỉ bỏ dòng #include "moving.h")
// *------------------------------------------------------------------
// *
// *------------------------------------------------------------------
// !-----------------------------------
// ! Lưu ý về việc xét thông số khi tăng giảm
// ! Các thay đổi thông số là dựa trên thông số hiện tại
// ! Các thông số không phải số nguyên không cần quan tâm làm tròn, chỉ cần đưa về int
// !-----------------------------------
// *CLASS: MagicBook
ItemType MagicBook::getType() const
{
    // TODO: get (1 dòng)
}
string MagicBook::str() const
{
    // TODO: trả về chuỗi biểu diễn (1 dòng)
}
bool MagicBook::canUse(Character *obj, Robot *robot)
{
    // TODO: điều kiện sử dụng
    // *Sau khi đấm Robot, EXP
}
void MagicBook::use(Character *obj, Robot *robot)
{
    // TODO: tăng EXP
}
// *CLASS: EnergyDrink
ItemType EnergyDrink::getType() const
{
    // TODO: get (1 dòng)
}
string EnergyDrink::str() const
{
    // TODO: trả về chuỗi biển diễn (1 dòng)
}
bool EnergyDrink::canUse(Character *obj, Robot *robot)
{
    // TODO: điều kiện sử dụng
    // *Sau khi đấm Robot, HP
}
void EnergyDrink::use(Character *obj, Robot *robot)
{
    // TODO: tăng HP
}
// *CLASS: FirstAid
ItemType FirstAid::getType() const
{
    // TODO: get (1 dòng)
}
string FirstAid::str() const
{
    // TODO: trả về chuỗi biểu diễn (1 dòng)
}
bool FirstAid::canUse(Character *obj, Robot *robot)
{
    // TODO: điều kiện sử dụng
    // *Sau khi đấm Robot, EXP || HP
}
void FirstAid::use(Character *obj, Robot *robot)
{
    // TODO: tăng HP
}
// *CLASS: ExcemptionCard
ItemType ExcemptionCard::getType() const
{
    // TODO: get (1 dòng)
}
string ExcemptionCard::str() const
{
    // TODO: trả về chuỗi biểu diễn (1 dòng)
}
bool ExcemptionCard::canUse(Character *obj, Robot *robot)
{
    // TODO: điều kiện sử dụng
    // *Trước khi đấm Robot, Sherlock, HP lẻ
}
void ExcemptionCard::use(Character *obj, Robot *robot)
{
    // TODO: sinh viên hiện thực theo tư duy code của mình (hàm có thể rỗng)
}
// *CLASS: PassingCard
PassingCard::PassingCard(int i, int j)
{
    // TODO: constructor gán giá trị cho thuộc tính challenge (i,j là tọa độ)
}
ItemType PassingCard::getType() const
{
    // TODO: get (1 dòng)
}
string PassingCard::str() const
{
    // TODO: trả về chuỗi biểu diễn (1 dòng)
}
bool PassingCard::canUse(Character *obj, Robot *robot)
{
    // TODO: điều kiện sử dụng
    // *Trước khi đấm Robot, Watson, HP chẵn
}
void PassingCard::use(Character *obj, Robot *robot)
{
    // TODO: tương tự ExcemptionCard khi thuộc tính challenge thích hợp, ngược lại sẽ trừ EXP
}
// *CLASS: BaseBag
BaseBag::BaseBag(int capacity)
{
    // TODO: constructor gán giá trị cho CÁC THUỘC TÍNH
}
BaseBag::~BaseBag()
{
    // TODO: destructor xóa các Node (Lưu ý phải xóa cả item trong Node đó)
}
bool BaseBag::insert(BaseItem *item)
{
    // TODO: thêm Node chứa item vào đầu Linked List
}
BaseItem *BaseBag::get(ItemType itemType)
{
    // TODO: Tìm và trả về item tương ứng với itemType
    // *Đảo vị trí trong BaseBag (2 cách phổ biến: swap Node hoặc con trỏ item của Node)
    // *Sau đó xóa Node (lưu ý cập nhật con trỏ head)
}
string BaseBag::str() const
{
    // TODO: trả về chuỗi biểu diễn
    // *"Bag[count=<thuộc tính size>;<danh sách tên các item cách nhau bởi dấu ,>]"
}
// *CLASS: SherlockBag
SherlockBag::SherlockBag(Sherlock *character)
    : BaseBag(
          // TODO: constructor class cha
      )
{
    // TODO: constructor class con
}
BaseItem *SherlockBag::get()
{
    // TODO: tìm và trả về item SHERLOCK CÓ THỂ SỬ DỤNG gấn đầu túi nhất, đảo lên đầu và xóa khỏi Linked List (cập nhật head)
}
// *CLASS: WatsonBag
WatsonBag::WatsonBag(Watson *character)
    : BaseBag(
          // TODO: constructor class cha
      )
{
    // TODO: constructor class con
}
BaseItem *WatsonBag::get()
{
    // TODO: tìm và trả về item WATSON CÓ THỂ SỬ DỤNG gấn đầu túi nhất, đảo lên đầu và xóa khỏi Linked List (cập nhật head)
}
