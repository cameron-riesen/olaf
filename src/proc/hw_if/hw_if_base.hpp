#ifndef HW_IF_BASE_HPP
#define HW_IF_BASE_HPP

class HwIfBase
{
public:
  HwIfBase();
  virtual ~HwIfBase();

  virtual void gpio_set_direction();
  virtual void gpio_set_value();

  virtual int i2c_write();
  virtual int i2c_read();

  virtual int spi_read();
  virtual int spi_write();

  virtual int uart_read();
  virtual int uart_write();

  
private:
};

#endif // HW_IF_BASE_HPP
