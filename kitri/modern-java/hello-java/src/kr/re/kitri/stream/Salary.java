package kr.re.kitri.stream;

// 모델 클래스
public class Salary {
    private int year;
    private String team;
    private String league;
    private String player;
    private long salary;

    public Salary() {}; // 파라미터 없는 생성자
    //파라미터 다 있는 생성자
    public Salary(int year, String team, String league, String player, long salary) {
        this.year = year;
        this.team = team;
        this.league = league;
        this.player = player;
        this.salary = salary;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public String getTeam() {
        return team;
    }

    public void setTeam(String team) {
        this.team = team;
    }

    public String getLeague() {
        return league;
    }

    public void setLeague(String league) {
        this.league = league;
    }

    public String getPlayer() {
        return player;
    }

    public void setPlayer(String player) {
        this.player = player;
    }

    public long getSalary() {
        return salary;
    }

    public void setSalary(long salary) {
        this.salary = salary;
    }

    @Override
    public String toString() {
        return "Salary{" +
                "year=" + year +
                ", team='" + team + '\'' +
                ", league='" + league + '\'' +
                ", player='" + player + '\'' +
                ", salary=" + salary +
                '}';
    }
}
